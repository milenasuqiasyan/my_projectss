
#include <iostream>

void minimumBribes (std::vector <int> q) 
{
    int bribes = 0;
    int n = q.size ();

    for (int i = 0; i < n; i++) {
        if (q[i] - (i + 1) > 2) {
            std::cout << "Too chaotic" << "\n";
            return;
        } 

        for (int j = std::max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) 
            {   bribes ++; }  
        } }     
        std:: cout << bribes <<"\n";  } 

int main() {
    std::vector <int> q(5);
    q[0] =2;
    q[1]= 1;
    q[2]= 3;
    q[3]= 4;
    q[4]= 5;

    minimumBribes(q);

    return 0;
}