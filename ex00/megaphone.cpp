#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str;
    if (ac == 1)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int j = 1;j < ac; j++)
    {
        str = av[j];
        for (size_t i = 0;i < str.length();i++){
            std::cout<<(char)toupper(str[i]);
        } 
    }
    std::cout<<std::endl;
    return 0;
}