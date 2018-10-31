// arithmetic
class Arith {
    public static int divide(int x, int y, int z) {
	return x / (y / z);
    }
	
    public static void main(String[] args)
    {
	int n = divide(3, 2, 1);
	int m = divide(1, 2, 3);
	int w = n * m;
	System.out.println(w);
    }
}
