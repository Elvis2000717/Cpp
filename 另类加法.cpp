class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		if (A == 0)
			return B;
		if (B == 0)
			return A;
		return addAB((A&B) << 1, A^B);
	}
};