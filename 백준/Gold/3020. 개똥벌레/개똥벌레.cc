#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H;
    cin >> N >> H;

    // 높이별 장애물 개수를 저장 (1부터 H까지 사용)
    vector<int> bottom(H + 1, 0); // 석순 (바닥에서 위로)
    vector<int> top(H + 1, 0);    // 종유석 (천장에서 아래로)

    for (int i = 0; i < N; i++) {
        int size;
        cin >> size;
        if (i % 2 == 0) {
            bottom[size]++; // 석순 높이 카운트
        } else {
            top[size]++;    // 종유석 높이 카운트
        }
    }

    // 누적 합 계산: 높이가 h 이상인 장애물의 개수를 구함
    // 높이 H부터 1까지 거꾸로 더하면 '해당 높이 이상'의 개수가 누적됨
    for (int i = H - 1; i >= 1; i--) {
        bottom[i] += bottom[i + 1];
        top[i] += top[i + 1];
    }

    int min_obstacles = N + 1; // 파괴할 장애물 최소값
    int count = 0;             // 최소값이 나타나는 구간의 수

    for (int i = 1; i <= H; i++) {
        // i번째 높이로 지나갈 때:
        // 바닥에서 i인 석순 + 천장에서 (H - i + 1)인 종유석 충돌
        int total = bottom[i] + top[H - i + 1];

        if (total < min_obstacles) {
            min_obstacles = total;
            count = 1;
        } else if (total == min_obstacles) {
            count++;
        }
    }

    cout << min_obstacles << " " << count << endl;

    return 0;
}
