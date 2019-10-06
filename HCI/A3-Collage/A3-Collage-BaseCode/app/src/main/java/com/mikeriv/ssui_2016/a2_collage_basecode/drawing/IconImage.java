package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;


import android.graphics.Bitmap;
import android.graphics.Canvas;

public class IconImage extends BaseVisualElement{
    private Bitmap MyImage;
    public IconImage(float xLoc, float yLoc, Bitmap MyImage) {
        super(xLoc, yLoc);
        this.MyImage = MyImage;
        setIntrinsicSize( MyImage);
    }
    @Override
    public boolean sizeIsIntrinsic() {
        return true;
    }
    @Override
    public void draw(Canvas onCanvas) {
        if (MyImage != null){
            onCanvas.drawBitmap(MyImage, 0, 0, null);//画图
        }
        super.draw(onCanvas);
    }

    private void setIntrinsicSize(Bitmap image){
        if (image != null){
            //Size.width = image.getWidth();
            //Size.height = image.getHeight();
        }
    }

}
