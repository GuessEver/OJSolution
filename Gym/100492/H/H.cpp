#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string ans[] = {
    "", "1", "2", "5", "14", "42", "165", "714", "3094", "14858", "79534", "447051", "2714690", "17395070", "114371070", "783152070", "5708587335", "43848093003", "342444658094", "2803119896185", "23619540863730", "201813981102615", "1793779293633437", "16342050964565645", "154170926013430326", "1518409177581024365", "15259825120722837478", "154870329715038713659", "1601991088154989174258", "16725278985898957454695", "177792163538134124432895"
};

int main() {
    int n, k = 1;
    freopen("handsome.in", "r", stdin);
    freopen("handsome.out", "w", stdout);
    while (scanf("%d", &n) == 1) {
        if (n == 0) {
            break;
        }
        printf("Case #%d: ", k++);
        cout << ans[n] << endl;
    }
    return 0;
}
