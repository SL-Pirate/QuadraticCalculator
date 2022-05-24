package org.alfa.quadcal;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import QuadCal.*;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void run(View view){
        double a;
        double b;
        double c;
        String[] output;

        try{
            String a_in = ((EditText)findViewById(R.id.a_in)).getText().toString();
            String b_in = ((EditText)findViewById(R.id.b_in)).getText().toString();
            String c_in = ((EditText)findViewById(R.id.c_in)).getText().toString();

            String[] input = {a_in, b_in, c_in};

            for (byte i=0;i<input.length;i++){
                switch(input[i]){
                    case "": input[i] = checkRound(i);
                        break;

                    case "-": input[i] = "-1";
                        break;

                    case ".": throw new dotException();
                }
            }

            a = Double.parseDouble(input[0]);
            b = Double.parseDouble(input[1]);
            c = Double.parseDouble(input[2]);

            Cal cal = new Cal(a, b, c);
            output = cal.run();

            String out;

            switch (output[5]){
                case "0": out = "Equation: " + output[0] + "\nDiscriminant: " + output[1] + "\nEquation has a: "+ output[7]+ "\nEquation is:\n\t"+ output[6] + "\nEquation has " + output[2];
                break;

                case "1": out = "Equation: " + output[0] + "\nDiscriminant: " + output[1] + "\nEquation has a: "+ output[7]+ "\nEquation is:\n\t"+ output[6] + "\nEquation has " + output[2] + "\nroots: " + output[3];
                break;

                case "2": out = "Equation: " + output[0] + "\nDiscriminant: " + output[1] + "\nEquation has a: "+ output[7]+ "\nEquation is:\n\t"+ output[6] + "\nEquation has " + output[2] + "\nroots: " + output[3] + "\n\t\t" + output[4];
                break;

                default: out = "something went wrong";
            }

            TextView x = findViewById(R.id.out);
            x.setText(out);
        }
        catch(notQuadraticException e){
            popup('e');
            TextView x = findViewById(R.id.out);
            x.setText(e.getMessage());
        }
        catch (dotException e){
            popup('f');
            TextView x = findViewById(R.id.out);
            x.setText(e.toString());
        }
        catch(Exception e){
            TextView x = findViewById(R.id.out);
            x.setText(e.toString());
        }
    }

    public void popup(char c) {
        if (c == 'e') {
            Toast.makeText(this, "a can't be zero", Toast.LENGTH_SHORT).show();
        }
        else if (c == 'f'){
            Toast.makeText(this, "Incomplete value", Toast.LENGTH_SHORT).show();
        }
        else {
            Toast.makeText(this, "Empty value of " + c + " has been replaced with 1", Toast.LENGTH_LONG).show();
        }
    }
    String checkRound(byte i){
        char e = 'e';
        switch (i){
            case 0: e = 'a';
                break;
            case 1: e = 'b';
                break;
            case 2: e = 'c';
        }
        popup(e);
        return "1";
    }
}