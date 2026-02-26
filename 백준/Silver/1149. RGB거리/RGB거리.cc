#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // cost[N][3]: N번째 집을 각각 R, G, B로 칠할 때의 최소 누적 비용
    vector<vector<int>> cost(N, vector<int>(3));

    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // DP 진행: 1번 집(두 번째 집)부터 마지막 집까지 최소값을 누적
    for (int i = 1; i < N; i++) {
        // 현재 집을 빨강(0)으로 칠할 경우: 이전 집은 초록(1) 또는 파랑(2) 중 최소값 선택
        cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
        // 현재 집을 초록(1)으로 칠할 경우: 이전 집은 빨강(0) 또는 파랑(2) 중 최소값 선택
        cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
        // 현재 집을 파랑(2)으로 칠할 경우: 이전 집은 빨강(0) 또는 초록(1) 중 최소값 선택
        cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
    }

    // 마지막 N-1번째 집의 R, G, B 비용 중 가장 작은 값을 정답으로 하여 출력
    cout << min({cost[N - 1][0], cost[N - 1][1], cost[N - 1][2]}) << endl;

    return 0;
}