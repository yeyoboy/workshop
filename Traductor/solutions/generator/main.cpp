#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <iostream>

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()


    int maxd[10] = {10,100,200,300,400,500,600,700, 900,1000};
    int maxw[10] = {100,1000,10000,1000000,10000000,100000000,1000000000,2000000000,2000000000,2000000000}

    for (int n=0; n<10; ++n) {
        std::uniform_int_distribution<> dis1(1, maxd[n]);
        std::uniform_int_distribution<> dis2(maxw[i]*-1, maxw[i]);

        //Use dis to transform the random unsigned int generated by gen into an int in [1, 6]
        int d = dis1(gen);
        int w = dis1(gen);
        int arr1[1000];
        int arr2[1000];

        ofstream in;
        ofstream out;

        stringstream ss;
        ss << n;
        string str = ss.str();


        in.open(str+".in");
        out.open(str+".out");

        in << d << " " << w << std::endl;

        for (int i = 0; i < d; i++) {
            arr1[i] = dis2(gen);
            arr2[i] = dis2(gen);
            in << arr1[i] << " " << arr2[i] << std::endl;
        }

        std::uniform_int_distribution<> dis3(1, d + 10);

        for (int i = 0; i < w; i++) {
            int q = dis3(gen);
            if (q < d) {
                in << arr1[q] << std::endl;
                out << arr2[q] <<std::endl;
            } else {
                in << dis2(gen) << std::endl;
                out << "C?" << std::endl;
            }
        }


        in.close();
        out.close();
    }

}
