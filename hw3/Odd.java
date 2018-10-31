// print some odd numbers
class Odd {
    public static int[] oddNumbers()
    {
	int numbers[] = {1, 3, 5, 7};
	return numbers;
    }
    
    public static void main(String[] args)
    {
	int[] odd = oddNumbers();
	
	for (int i = 0; i < 4; i ++) {
	    System.out.println(odd[i]);
	}
    }
}
