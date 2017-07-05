#include <dirent.h>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

vector<string> getFileNames (string dir)
{
    vector<string> file_lists;
 
    DIR *dp;
    struct dirent *ep;
    dp = opendir (dir.c_str());
 
    if (dp != NULL)
    {
        while (ep = readdir (dp)){
            if (strcmp(ep->d_name, ".") && strcmp(ep->d_name, ".."))
                file_lists.push_back(dir + "/"+ ep->d_name);
        }
 
        (void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");
 
    return file_lists;
}

int main()
{
    vector<string> file_lists = getFileNames("/home/dongwonshin/Desktop/LC_text_results"); 
    for (int i = 0 ; i < file_lists.size() ; i++)
        cout << file_lists[i] << endl;
    return 0;
}