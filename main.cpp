#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

struct Point{
    double x;
    double y;
};


std::vector <Point> terribleTrigonometry(unsigned  int n){
    std::vector <Point> points(n);
    const double PI = 3.141592653589793;
    double alpha = 2 * PI / n;
    points[0] = {1, 0};
    points[1] = {cos(alpha), sin(alpha)};
    for (int i = 2; i < n; i ++){
        auto x =  points[i-1].x * points[1].x - points[1].y * points[i-1].y; //cos суммы
        auto y = points[1].x * points[i-1].y + points[i-1].x * points[1].y; //синус суммы
        points[i] = {x, y};
    }
    for (auto i = 0; i < points.size(); i ++){
        std::cout << points[i].x << " " << points[i].y << std::endl;
    }
    if (n == 0){
        return {

        };
    }
    return points;
}
int main(){
    unsigned int n;
    std::cin >> n;

    terribleTrigonometry(n);

}
