using namespace std;

long long solution(int price, int money, int count)
{
    long long money_l = money;

    for (int i=0; i<count; i++) {
        money_l -= price * (i+1);
    }
    
    if (money_l > 0) return 0;
    return -money_l;
}