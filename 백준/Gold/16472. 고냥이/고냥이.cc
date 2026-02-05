#include <iostream>
#include <string>
#include <vector>

int main() {
    int max_variations;
    std::string given_str;
    std::cin >> max_variations;
    std::cin >> given_str;

    // 각 알파벳 등장 횟수 저장 (a-z: 26개)
    int occur_count[26] = { 0 };
    int left = 0, right = 0;
    int num_variations = 0; // 현재 구간에 포함된 알파벳 종류 수
    int max_len = 0;

    // 투 포인터 탐색 (right 포인터를 하나씩 이동)
    for (right = 0; right < given_str.length(); ++right) {
        // given_str 의 각 글자가 'a' 로부터 얼마나 떨어져있는지를 통해
        // occur_count 에서 어딜 바라봐야 하는지를 산출 ('b' 라면 'a' 와 차이값, 1이 나옴)
        // 올바른 알파벳 등장 횟수 증가를 위함
        int add_idx = given_str[right] - 'a';

        // 처음 등장하는 알파벳이면 종류 수 증가
        if (occur_count[add_idx] == 0) {
            num_variations++;
        }
        occur_count[add_idx]++;

        // 알파벳 종류가 N개를 초과하면 left 포인터를 이동시켜 범위를 좁힘
        while (num_variations > max_variations) {
            // given_str 의 각 글자가 'a' 로부터 얼마나 떨어져있는지를 통해
            // occur_count 에서 어딜 바라봐야 하는지를 산출 ('b' 라면 'a' 와 차이값, 1이 나옴)
            // 올바른 알파벳 등장 횟수 감소를 위함
            int remove_idx = given_str[left] - 'a';
            occur_count[remove_idx]--;

            // 해당 알파벳의 개수가 0이 되면 알파벳 총 종류 수 감소
            if (occur_count[remove_idx] == 0) {
                num_variations--;
            }
            left++; // 왼쪽 포인터 전진
        }

        // 최대 길이 갱신
        max_len = std::max(max_len, right - left + 1);
    }

    std::cout << max_len << std::endl;

    return 0;
}