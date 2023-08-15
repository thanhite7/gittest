class A
{
    int a = 10;
    private int b=20;
    public void method()
    {
        System.out.println("A");
    }
}
class ccc extends A
{
    public static void main(String[] args)
    {
        ccc v = new ccc();
        v.method();
        System.out.println(v.a+" ");
        System.out.println(v.b+" ");
