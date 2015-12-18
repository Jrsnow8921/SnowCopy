#include <iostream>
#include <sys/sendfile.h>  
#include <fcntl.h>         
#include <unistd.h>        
#include <sys/stat.h>      
#include <sys/types.h>     
#include <ctime>
using namespace std;

int main() {
    clock_t start, end;
    start = clock();

    int source = open("test.txt", O_RDONLY, 0);
    int dest = open("test_copy.txt", O_WRONLY | O_CREAT /*| O_TRUNC/**/, 0644);

    struct stat stat_source;
    fstat(source, &stat_source);

    sendfile(dest, source, 0, stat_source.st_size);

    close(source);
    close(dest);

    end = clock();

    cout << "COPY COMPLETE" << "\n" << "Succes" << "\n";
    cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
    cout << "CPU-TIME START " << start << "\n";
    cout << "CPU-TIME END " << end << "\n";
    cout << "CPU-TIME END - START " <<  end - start << "\n";
    cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
