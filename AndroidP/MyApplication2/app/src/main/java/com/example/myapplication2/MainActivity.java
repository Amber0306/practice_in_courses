package com.example.myapplication2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    //public static int i=20;

    // @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {

            Button button=(Button)findViewById(R.id.button_1);
            button.setOnClickListener(new MyButtonListener());
            String input="input:?";
            TextView note=(TextView)findViewById(R.id.text_main);
            note.setText(input);


            Log.d("MainActivity", "onCreate: executive");
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

    private class MyButtonListener implements View.OnClickListener {
        @Override
        public void onClick(View view) {
            EditText editText = (EditText) findViewById(R.id.edit_text);
            TextView v1 = (TextView) findViewById(R.id.text_main);
            TextView v2 = (TextView) findViewById(R.id.text_fib_number);

            String input = editText.getText().toString();
            try {
                int index = Integer.parseInt(input);
                if (index <= 0) {
                    throw new Exception();
                }

                String str1 = getResources().getString(R.string.index);
                str1 = String.format(str1, index);
                v1.setText(str1);

                int num = calculateFibonacciNumber(index);
                String str2 = getResources().getString(R.string.description_fibonacci);
                str2 = String.format(str2, num);
                v2.setText(str2);


            } catch (Exception e) {
                v2.setText("Wrong Input");
            }

        }

    }
}


