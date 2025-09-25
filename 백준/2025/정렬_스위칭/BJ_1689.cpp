#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum Point_t
{
    start, end
};

struct _point
{
    double x;
    Point_t where;
};

int main()
{
    int n;
    cin >> n;

    vector<_point> points;
    for (int i = 0; i < n; ++i)
    {
        double x1, x2;
        cin >> x1 >> x2;
        points.push_back({ x1, Point_t::start });
        points.push_back({ x2, Point_t::end });
    }

    sort(points.begin(), points.end(), [](_point a, _point b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.where > b.where; // start�� end���� ���� ó��
        });

    int cnt = 0, max_cnt = 0;
    double ans_start = 0, max_start = 0, max_end = 0;
    for (auto p: points)
    {
        if (p.where == Point_t::start)
        {
            cnt++;
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                max_start = p.x;
            }
        }
        else // p.where == Point_t::end
        {
            if (cnt == max_cnt)
                max_end = p.x;
            cnt--;
        }
    }

    // cout << max_cnt << endl;
    cout << "max count: " << max_cnt << endl;
    cout << "max: [" << max_start << ", " << max_end << "]" << endl;
    return 0;
}
