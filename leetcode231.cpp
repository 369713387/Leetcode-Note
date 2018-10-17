bool IsPowerOfTwo1(int n)
{
	return n > 0 && (n & (n - 1)) == 0;
}
bool IsPowerOfTwo2(int n)
{
	return n % 2 == 0 ? n == 0 ? false : IsPowerOfTwo2(n / 2) : n == 1;
}
bool IsPowerOfTwo3(int n)
{
	if (n <= 0)
		return false;
	while (true)
	{
		if (n == 1)
			return true;
		if (n % 2 != 0)
			return false;
		n /= 2;
	}
}

