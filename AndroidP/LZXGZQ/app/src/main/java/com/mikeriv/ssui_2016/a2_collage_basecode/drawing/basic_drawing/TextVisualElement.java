package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.basic_drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Typeface;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class TextVisualElement extends BaseVisualElement {

    private String Text;
    private float textSize;
    private Typeface typeFace;

    public TextVisualElement(float x, float y, String text, Typeface face, float textSize){
        this.x0=x;
        this.y0=y;
        Text =text;
        this.textSize=textSize;
        this.typeFace=face;
    }

    public float getW(){
        return this.Text.length()*textSize+x0;
    }

    @Override
    public float getH(){
        return this.textSize+y0;
    }

    @Override
    public void draw(Canvas onCanvas){
        Paint paint =new Paint();
        paint.setColor(Color.BLACK);
        paint.setTextSize(textSize);
        paint.setTypeface(typeFace);
        onCanvas.save();
        onCanvas.drawText(Text,x0,y0+textSize,paint);
        //此处使用不当，但是可以将基线下调以显示方便使用
        onCanvas.restore();
    }
}
