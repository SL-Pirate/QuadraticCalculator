package org.alfa.quadcal;

public class dotException extends Exception{
    @Override
    public String getMessage(){
        return "Please enter a valid number";
    }

    @Override
    public String toString(){
        return "\".\" is not a valid number.";
    }
}
