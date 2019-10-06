package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Typeface;

/**
 * Created by dell on 2019/4/23.
 */

public class TextVisualElement extends BaseVisualElement{
    private String mText;
    private float mtextSize;
    private Typeface mface;

    public TextVisualElement(float x, float y, String text, Typeface face, float textSize){
        this.mX=x;
        this.mY=y;
        mText =text;
        this.mtextSize=textSize;
        this.mface=face;
    }

    public float getW(){
        //return 600.0f;
        return this.mText.length()*mtextSize+mX;
    }

    @Override
    public float getH(){
        //return 600.0f;
        return this.mtextSize+mY;
    }

    @Override
    public void draw(Canvas onCanvas){
        Paint mPaint =new Paint();
        mPaint.setColor(Color.BLACK);
        mPaint.setTextSize(mtextSize);
        mPaint.setTypeface(mface);
        //mPaint.setTextAlign(Paint.Align.LEFT);
//      mPaint.setAntiAlias(false);
        onCanvas.save();
        onCanvas.drawText(mText,mX,mY+mtextSize,mPaint);//此处使用不当，但是可以将基线下调以显示方便使用
        onCanvas.restore();
    }
}
