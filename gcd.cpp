#include <stdio.h>
#include <gmp.h>
#include <iostream>
using namespace std;
void gcd(mpz_t a,mpz_t b)
{
	mpz_t rem;
	mpz_init(rem);
	mpz_mod(rem,b,a);
	if(mpz_cmp_ui(rem,0)==0)
	{
		gmp_printf ("gcd of given numbers is %Zd\n", a);
		return;
	}
	cout<<"rem="<<rem<<endl;
	gcd(rem,a);
}
int main (void)
{
	mpz_t a,b;
	mpz_init(a);
	mpz_init(b);
	gmp_scanf ("%Zd",a);
	gmp_scanf ("%Zd",b);
	int comp=mpz_cmp(a,b);
	if(comp>0)gcd(b,a);
	else gcd(a,b);
	gmp_rand(a,15);
	cout<<a<<endl;
	return 0;
}