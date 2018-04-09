class Solution {
public:
    double dist(vector<int> &a, vector<int> &b){
        return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1]-b[1]) * (a[1]-b[1]));
    }
    double area(double a, double b, double c){
        double p = (a + b + c)/2;
        return sqrt(p * (p-a) * (p-b) * (p-c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        for (int i=0; i<points.size(); i++){
            for (int j=i+1; j<points.size(); j++){
                for (int k=j+1; k<points.size(); k++){
                    double a = dist(points[i], points[j]);
                    double b = dist(points[j], points[k]);
                    double c = dist(points[k], points[i]);
                    result = max(result, area(a, b, c));
                }
            }
        }
        return result;
    }
};