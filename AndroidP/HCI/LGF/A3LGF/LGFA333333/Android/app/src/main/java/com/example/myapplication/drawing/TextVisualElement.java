package com.example.myapplication.drawing;

import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Typeface;

import com.example.myapplication.drawing.pre.BasicVisualElement;

public class TextVisualElement extends BasicVisualElement {
    String txt;
    Typeface fce;
    float txtsize;
    public TextVisualElement(float x, float y, String text, Typeface face, float textSize){
        setX(x);
        setY(y);
        txt=text;
        fce=face;
        txtsize=textSize;
        setH(50);
        setW(200);
    }

    public void setText(String text){
        txt=text;
    }

    public void setTypeFace(Typeface face){
        fce=face;
    }

    public void setTextSize(float textSize){
        txtsize=textSize;
    }

    @Override
    public void draw(Canvas onCanvas) {
        super.draw(onCanvas);
        Paint p =new Paint();
        p.setTextSize(txtsize);
        p.setTypeface(fce);
        onCanvas.drawText(txt,0,txt.length(),getX(),getY()+50,p);
    }
}
