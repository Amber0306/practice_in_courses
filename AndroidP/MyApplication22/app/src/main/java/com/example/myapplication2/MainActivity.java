package com.example.myapplication2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public static int i=20;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {
            Log.d("MainActivity", "onCreate: executive");

            String str1 = getResources().getString(R.string.index);
            str1 = String.format(str1, i);
            TextView v1 = (TextView) findViewById(R.id.text_main);
            v1.setText(str1);

            int num = calculateFibonacciNumber(i);
            String str2 = getResources().getString(R.string.description_fibonacci);
            str2 = String.format(str2, num);
            TextView v2 = (TextView) findViewById(R.id.text_fib_number);
            v2.setText(str2);
        }catch(Exception e)
        {
            Log.d("exception",e.getMessage());
        }
    }


    /* Takes an integer i and calculates the i-th fibonacci number and
     * returns this number
     * @param i - the i-th fib number to calculate
     * @return fibNumber - the calculated fib number
     */
// TODO: fill in method

    public static int  calculateFibonacciNumber(int i)
    {
        if(i==1||i==2)return 1;
        else
        {
            return calculateFibonacciNumber(i-1)+calculateFibonacciNumber(i-2);
        }
    }



}


