#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <set>
#include <fstream>

#define MAX_SIZE 1000
char inputString[MAX_SIZE];

int main(){
    int num;

//    std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/test_points.txt");
    std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/point_conv_0214.txt");

for(int k=0; k<50; k++){
    inFile.getline(inputString,100);
    std::stringstream sts;
    sts << inputString;
    std::cout<<sts.str()<<std::endl;
    std::string x;
    std::string y;
    std::string z;

    sts >> x;
    sts >> y;
    sts >> z;

    double x_ = atof(x.c_str());
    double y_ = atof(y.c_str());
    double z_ = atof(z.c_str());

//    std::string test_sts;
//    std::vector<std::string> vec(std::begin(test_sts),std::end(test_sts));
    std::cout<<x_<<std::endl;
    std::cout<<y_<<std::endl;
    std::cout<<z_<<std::endl;
    

//    vec << "test is right?";
//    std::cout<<vec.size()<<std::endl;
}
/*
    std::string word1, word2;
    std::stringstream cast;
    cast <<"helloworld hi? 12341234";
    std::cout<<cast.str()<<std::endl;

    cast >>word1;
    cast >> word2;
    cast >> num;
    std::cout<<word1<<" "<<word2<<" "<<num<<std::endl;
*/
    return 0;
}