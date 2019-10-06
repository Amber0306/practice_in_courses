package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.basic_drawing;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class IconImage extends BaseVisualElement
{
    Bitmap bitmap;
    Paint paint;
    public IconImage(float x, float y, Bitmap image){
        this.x0=x;
        this.y0=y;
        this.bitmap=image;
        paint=new Paint();
    }

    @Override
    public boolean sizeIsIntrinsic() {
        // default value -- override in subclasses that need to...
        return true;
    }

    @Override
    public float getW(){
        //return this.getW();
        return this.bitmap.getWidth();
    }

    @Override
    public float getH(){
        //return this.getH();
        return this.bitmap.getHeight();
    }

    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.translate(x0,y0);
        onCanvas.drawBitmap(bitmap,0,0,paint);
        onCanvas.restore();
    }
}
