#!/usr/bin/env bash

PROGRAM="./PmergeMe"
RESULTS_FILE="tested.txt"
FAILURES_FILE="failures.txt"
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

usage() {
    echo "Usage:"
    echo "  $0 [--optimal N] n1 n2 n3 ..."
}

optimal_for_n() {
    local n=$1
    local sum=0
    local k
    local p
    for ((k = 1; k <= n; k++)); do
        p=0
        while [ $((1 << (p + 2))) -lt $((3 * k)) ]; do
            p=$((p + 1))
        done
        sum=$((sum + p))
    done
    echo "$sum"
}

factorial() {
    local n=$1
    local result=1
    for ((i=2; i<=n; i++)); do
        result=$((result * i))
    done
    echo "$result"
}

parse_args() {
    EXPECTED_OPTIMAL=""
    NUMBERS=()
    while [ $# -gt 0 ]; do
        case "$1" in
            --optimal)
                shift
                [ $# -eq 0 ] && exit 1
                EXPECTED_OPTIMAL="$1"
                ;;
            -h|--help)
                usage
                exit 0
                ;;
            *)
                NUMBERS+=("$1")
                ;;
        esac
        shift
    done
    [ "${#NUMBERS[@]}" -lt 1 ] && { usage; exit 1; }
}

run_test() {
    local args=("$@")
    local out
    local ret
    local vec_cmp
    local deq_cmp
    local after_line
    local actual_sorted
    local expected_sorted
    local case_failed=0

    out=$(PMERGEME_SHOW_COMPARISONS=1 "$PROGRAM" "${args[@]}" 2>&1)
    ret=$?

    permutations=$((permutations + 1))

    vec_cmp=$(echo "$out" | sed -n 's/^Comparisons (std::vector): \([0-9][0-9]*\)$/\1/p')
    deq_cmp=$(echo "$out" | sed -n 's/^Comparisons (std::deque): \([0-9][0-9]*\)$/\1/p')
    [ -z "$vec_cmp" ] && vec_cmp="?"
    [ -z "$deq_cmp" ] && deq_cmp="?"

    if [ "$vec_cmp" != "?" ] && [ "$vec_cmp" -gt "$max_vec" ]; then
        max_vec=$vec_cmp
        max_vec_args="${args[*]}"
    fi
    if [ "$deq_cmp" != "?" ] && [ "$deq_cmp" -gt "$max_deq" ]; then
        max_deq=$deq_cmp
        max_deq_args="${args[*]}"
    fi

    [ $ret -ne 0 ] && case_failed=1

    after_line=$(echo "$out" | sed -n 's/^After:[[:space:]]*//p' | sed -n '1p')
    actual_sorted=$(echo "$after_line" | xargs)
    expected_sorted=$(printf "%s\n" "${args[@]}" | sort -n | tr '\n' ' ' | sed 's/[[:space:]]*$//')
    [ "$actual_sorted" != "$expected_sorted" ] && case_failed=1

    if [ "$case_failed" -eq 1 ]; then
        fail_count=$((fail_count + 1))
        fails+=("${args[*]} | vec=$vec_cmp deq=$deq_cmp")
    fi

    echo "${args[*]} | vec=$vec_cmp deq=$deq_cmp ret=$ret" >> "$RESULTS_FILE"

    local ok_count=$((permutations - fail_count))
    printf "\r[%d/%d] OK=${GREEN}%d${RESET} FAIL=${RED}%d${RESET} maxVec=%s maxDeq=%s" \
        "$permutations" "$total_perms" "$ok_count" "$fail_count" "$max_vec" "$max_deq"
}

permute() {
    local arr=("$@")
    local n=${#arr[@]}

    local c=()
    local i
    local swap_index
    local tmp
    for ((i = 0; i < n; i++)); do c[i]=0; done

    run_test "${arr[@]}"

    i=1
    while [ $i -lt $n ]; do
        if [ "${c[$i]}" -lt $i ]; then
            if (( i % 2 == 0 )); then
                swap_index=0
            else
                swap_index=${c[$i]}
            fi

            tmp=${arr[$i]}
            arr[$i]=${arr[$swap_index]}
            arr[$swap_index]=$tmp

            run_test "${arr[@]}"

            c[$i]=$((c[$i] + 1))
            i=1
        else
            c[$i]=0
            i=$((i + 1))
        fi
    done
}

parse_args "$@"
n=${#NUMBERS[@]}
total_perms=$(factorial "$n")
if [ -z "$EXPECTED_OPTIMAL" ]; then
    EXPECTED_OPTIMAL=$(optimal_for_n "$n")
fi
permutations=0
fail_count=0
fails=()
max_vec=0
max_deq=0
max_vec_args=""
max_deq_args=""
: > "$RESULTS_FILE"
: > "$FAILURES_FILE"

echo "Testing ${n} numbers (${total_perms} permutations)..."
echo "Expected optimal (worst-case) comparisons: $EXPECTED_OPTIMAL"
permute "${NUMBERS[@]}"

printf "\n\n"

echo "======================="
echo "Total permutations: $permutations"
echo "Failures: $fail_count"
echo "Max vector comparisons: $max_vec (input: $max_vec_args)"
echo "Max deque comparisons: $max_deq (input: $max_deq_args)"
echo "Detailed results: $RESULTS_FILE"

if [ "$fail_count" -gt 0 ]; then
    printf "%s\n" "${fails[@]}" > "$FAILURES_FILE"
    echo "Failing inputs: $FAILURES_FILE"
fi

if [ "$fail_count" -eq 0 ] && [ "$max_vec" -le "$EXPECTED_OPTIMAL" ] && [ "$max_deq" -le "$EXPECTED_OPTIMAL" ]; then
    echo -e "${GREEN}PASS${RESET}: sorted correctly and comparisons <= optimal ($EXPECTED_OPTIMAL)."
    exit 0
fi
echo -e "${RED}FAIL${RESET}: expected <= $EXPECTED_OPTIMAL, got vec=$max_vec, deq=$max_deq, failures=$fail_count."
exit 2
