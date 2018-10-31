// multiply the elements of a vector
class Multiply {
    public static void main(String argv[]) {
	int a[] = {1, 2, 3};
	int total = 1;

	for(int i = 0; i <= 3; i++)
	    total *= a[i];

	System.out.println(total + " = 6");
    }
}
