#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

double xA, yA, xB, yB, xC, yC;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //receive input
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    
    //test for exception case to print -1
    double tmp1, tmp2;
    bool flag = false;
    if(yA >= yB && yA >= yC) {
        tmp1 = (yA - yB) / (xA - xB);
        tmp2 = (yA - yC) / (xA - xC);
        // cout << "AB AC " << tmp1 << " " << tmp2 << endl;
        if(tmp1 == tmp2)
            flag = true;
    }
    if(yB >= yC && yB >= yA) {
        tmp1 = (yB - yC) / (xB - xC);
        tmp2 = (yB - yA) / (xB - xA);
        // cout << "BC BA " << tmp1 << " " << tmp2 << endl;
        if(tmp1 == tmp2)
            flag = true;
    }
    if(yC >= yB && yC >= yA) {
        tmp1 = (yC - yB) / (xC - xB);
        tmp2 = (yC - yA) / (xC - xA);
        // cout << "CB CA " << tmp1 << " " << tmp2 << endl;
        if(tmp1 == tmp2)
            flag = true;
    }
    if(flag == true) {
        cout << -1.0;
        return 0;
    }
    else {
        // cout << "flag is false" << endl;

        double AB = sqrt(((xA - xB) * (xA - xB)) + ((yA - yB) * (yA - yB)));
        double AC = sqrt(((xA - xC) * (xA - xC)) + ((yA - yC) * (yA - yC)));
        double BC = sqrt(((xB - xC) * (xB - xC)) + ((yB - yC) * (yB - yC)));

        double option1 = (AB + BC) * 2;
        double option2 = (AC + BC) * 2;
        double option3 = (AB + AC) * 2;
        
        // cout << option1 << " " << option2 << " " << option3 << endl;
        
        if(option1 >= option2 && option2 >= option3) {
            printf("%.15g", option1 - option3);
            // cout << option1 - option3;
            return 0;
        }
        if(option1 >= option3 && option3 >= option2) {
            printf("%.15g", option1 - option2);
            // cout << option1 - option2;
            return 0;
        }
        if(option2 >= option1 && option1 >= option3) {
            printf("%.15g", option2 - option3);
            // cout << option2 - option3;
            return 0;
        }
        if(option2 >= option3 && option3 >= option1) {
            printf("%.15g", option2 - option1);
            // cout << option2 - option1;
            return 0;
        }
        if(option3 >= option1 && option1 >= option2) {
            printf("%.15g", option3 - option2);
            // cout << option3 - option2;
            return 0;
        }
        if(option3 >= option2 && option2 >= option1) {
            printf("%.15g", option3 - option1);
            // cout << option3 - option1;
            return 0;
        }
    }
    return 0;
}