1. Your task is to write a C++ program to read a sentence from the keyboard, and print to the screen the sentence in the reversed order. 

 

#include <iostream> 

#include <string> 

#include <algorithm> 

using namespace std; 

  

int main() { 

          string sentence; 

          getline(cin, sentence); 

          reverse(sentence.begin(), sentence.end()); 

          cout << sentence <<endl; 

     

    return 0; 

} 

 

2. Your task is to write a C++ program including 2 classes Point and Line to store four points (A, B, C, D) on the two-dimension plane. The program determines the intersection between line AB and line CD.  

Input: The first line contains two real numbers separated by a space describing the point A. Similarly, the second, third, and fourth lines contain data for points B, C, and D, respectively.  

Output: Write to the screen the intersection point between AB and CD. Write “NO” if there is no intersection, or “MANY” if AB and CD have many intersection points. 

 

#include <iostream> 

#include <iomanip> 

using namespace std; 

class Point { public: double x, y; Point(double x = 0, double y = 0) : x(x), y(y) {} }; 

class Line { public: Point p1, p2; Line(Point a, Point b) : p1(a), p2(b) {} 

static int intersection(Line l1, Line l2, Point &intersect) { 
    double x1 = l1.p1.x, y1 = l1.p1.y; 
    double x2 = l1.p2.x, y2 = l1.p2.y; 
    double x3 = l2.p1.x, y3 = l2.p1.y; 
    double x4 = l2.p2.x, y4 = l2.p2.y;  

 
     
    double det = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4); 
     
    if (det == 0) { 
        if ((y3 - y1) * (x2 - x1) == (y2 - y1) * (x3 - x1)) { 
            return 2; 
        } 
        return 0;  
    } 
     
    intersect.x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / det; 
    intersect.y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / det; 
    return 1;  
} 
  

}; 

int main() { Point A, B, C, D; cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y; 

Line AB(A, B), CD(C, D); 
Point intersection; 
 
int result = Line::intersection(AB, CD, intersection); 
 
if (result == 2) { 
    cout << "MANY" << endl; 
} else if (result == 0) { 
    cout << "NO" << endl; 
} 
 
return 0; 
  

} 

3. Your task is to write a C++ program to find the greatest common divisor of two integer numbers.  

Input: Read two positive integer numbers m and n from the keyboard Output: Write to the screen the greatest common divisor of m and n. 

 

#include <iostream> 

using namespace std; 

  

int gcd(int a, int b) { 

    while (b != 0) { 

        int temp = b; 

        b = a % b; 

        a = temp; 

 } 

    return a; 

} 

 int main() { 

    int m, n; 

cin >> m >> n; 

 cout << gcd(m, n) << endl; 

    return 0; 

} 

 

4. Your task is to write a C++ program to read a list of integer numbers from the keyboard and write to the screen the list of numbers after being increasingly sorted. 

Input: − The first line contains an integer number n that is the number of numbers on the list. 

  − The second line contains n integer numbers separated by a space. 	  

Output: Write to the screen n sorted numbers in one line. 

 

#include <iostream> 

#include <vector> 

#include <algorithm> 

  

using namespace std; 

  

int main() { 

    int n; 

    cin >> n; 

     

    vector<int> numbers(n); 

    for (int i = 0; i < n; i++) { 

        cin >> numbers[i]; 

    } 

  

    sort(numbers.begin(), numbers.end()); 

    for (int num : numbers) { 

        cout << num << " "; 

    } 

    cout << endl; 

     

    return 0; 

} 

 

5. Given 5 different numbers, your task is to write a C++ program to calculate the sum of the greatest number and the smallest number.  

Input: One line contains 5 real numbers separated by a space.  

Output: Write to the screen the sum of the greatest number and the smallest number. 

 

#include <iostream> 

#include <vector> 

#include <algorithm> 

  

using namespace std; 

  

int main() { 

    vector<double> numbers(5); 

    for (int i = 0; i < 5; i++) { 

        cin >> numbers[i]; 

    } 

     

    double minNum = *min_element(numbers.begin(), numbers.end()); 

    double maxNum = *max_element(numbers.begin(), numbers.end()); 

     

    cout << (minNum + maxNum) << endl; 

     

    return 0; 

} 