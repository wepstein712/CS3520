// print some odd and even numbers
class OddEven {
    public static int[] doReturn(int[] ret)
    {
	return ret;
    }
    
    public static int[] oddNumbers()
    {
	int numbers[] = {1, 3, 5, 7};
	return doReturn(numbers);
    }
    
    public static int[] evenNumbers()
    {
	int numbers[] = {2, 4, 6, 8};
	return doReturn(numbers);
    }
    
    public static void main(String[] args)
    {
	int[] odd = oddNumbers();
	int[] even = evenNumbers();
	
	for (int i = 0; i < 4; i ++) {
	    System.out.println(odd[i] + " " + even[i]);
	}
    }
}
