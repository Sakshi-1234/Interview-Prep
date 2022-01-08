#include <stdio.h>

float squareRoot(int number, int precision)
{
    int start = 0, end = number;
    int mid;

    float ans;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid * mid == number)
        {
            ans = mid;
            break;
        }

        if (mid * mid < number)
        {
            start = mid + 1;
            ans = mid;
        }

        else
        {
            end = mid - 1;
        }
    }

    float increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= number)
        {
            ans += increment;
        }

        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}


int main()
{
    int N;
    int pre;
    printf("Enter the number: ");
    scanf("%d", &N);
    printf("Enter precision: ");
    scanf("%d", &pre);
    float result;
    result = squareRoot(N, pre);
    printf("%f", result);
    return 0;
}