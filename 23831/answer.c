#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

int N, A, B, *PQ, *R, *S;
int *remainderPQ;
int result = 0;

void loop(int i, int a, int b, bool wasR, int lastvalue)
{
	if(i == N)
	{
		if(result < lastvalue)
			result = lastvalue;
		return;
	}

	if(N - i == B - b)
	{
		if(result < lastvalue + remainderPQ[i])
			result = lastvalue = remainderPQ[i];
		return;
	}

	if(a < A)
		loop(i + 1, a + 1, b, false, lastvalue + S[i]);

	if(wasR == false)
		loop(i + 1, a, b, true, lastvalue + R[i]);

	loop(i + 1, a, b + 1, false, lastvalue + PQ[i]);
}

int main(void)
{
	scanf("%d", &N);
	scanf("%d %d", &A, &B);

	PQ = malloc(N * sizeof(int));
	R = malloc(N * sizeof(int));
	S = malloc(N * sizeof(int));
	remainderPQ = malloc(N * sizeof(int));

	for(int i = 0; i < N; i++)
	{
		int p, q, r, s;
		scanf("%d %d %d %d", &p, &q, &r, &s);
		PQ[i] = max(p, q);
		R[i] = r;
		S[i] = s;
	}

	int sumPQ = 0;
	for(int i = 0; i < N; i++)
		sumPQ += PQ[i];

	remainderPQ[0] = sumPQ;
	for (int i = 1; i < N; i++)
		remainderPQ[i] = remainderPQ[i - 1] - PQ[i - 1];

	loop(0, 0, 0, false, 0);
	printf("%d", result);
	free(PQ);
	free(R);
	free(S);
	free(remainderPQ);
}
