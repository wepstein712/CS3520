// print negative numbers
class Negative {
    public static int[] numbers()
    {
	int[] numbers = {-5, -6, -7, -8};
	int[] ret = numbers;
	return ret;
    }

    public static void displayBoth(int others[])
    {
	int[] numbers = {-1, -2, -3, -4};
  
	for (int i = 0; i < 4; i ++) {
	    System.out.println(numbers[i]);
	}
	for (int i = 0; i < 4; i ++) {
	    System.out.println(others[i]);
	}
    }

    public static void main(String[] args)
    {
	displayBoth(numbers());
    }
}
