package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;



public class IconImage extends BaseVisualElement{
    Bitmap image;
    Paint mPaint;
    public IconImage(float x, float y, Bitmap image){
        this.mX=x;
        this.mY=y;
        this.image=image;
       // this.mW=this.image.getWidth();
       // this.mH=this.image.getHeight();
        mPaint=new Paint();
    }

    @Override
    public boolean sizeIsIntrinsic() {
        // default value -- override in subclasses that need to...
        return true;
    }

    @Override
    public float getW(){
        //return this.getW();
        return this.image.getWidth();
    }

    @Override
    public float getH(){
        //return this.getH();
        return this.image.getHeight();
    }

    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.translate(mX,mY);
        onCanvas.drawBitmap(image,0,0,mPaint);
        onCanvas.restore();
    }
}
