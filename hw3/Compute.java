// compute something
class Compute {
    public static double compute(int x)
    {
	if (x <= 0) {
	    return 0.0;
	}
	
	double localdata1;
	double localdata2;
	double localdata3;
	double localdata4;
	double localdata5;
	
	localdata1 = compute(x - 1);
	localdata2 = compute(x - 2);
	localdata3 = compute(x - 3);
	localdata4 = compute(x - 4);
	localdata5 = compute(x - 5);
	
	return localdata1 - localdata2 + localdata3 - localdata4 + localdata5;
    }
    
    public static void main(String[] args)
    {
	System.out.println(compute(1000000));
    }
}
