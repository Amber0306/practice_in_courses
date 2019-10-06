package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Typeface;

public class TextVisualElement extends BaseVisualElement {
    private String string;
    private Typeface MyTypeface;
    private float MyFontSize;
    public TextVisualElement(float xLoc, float yLoc, String string, Typeface typeface, float fontSize) {
        super(xLoc, yLoc);
        this.string = string;
        this.MyTypeface = typeface;
        this.MyFontSize = fontSize;
        setIntrinsicSize(fontSize * string.length(), fontSize);
    }
    @Override
    public boolean sizeIsIntrinsic() {
        return true;
    }
    @Override
    public void draw(Canvas onCanvas) {
        Paint paint = new Paint();
        paint.setTypeface(MyTypeface);
        paint.setTextSize(MyFontSize);
        onCanvas.drawText(string, 5, 20, paint);
        super.draw(onCanvas);
    }
    public String getString() {
        return string;
    }
    public void setString(String string) {
        this.string = string;
        setIntrinsicSize(MyFontSize * string.length(), MyFontSize);
    }
    private void setIntrinsicSize(float width, float height){
        //this.width = width;
        //this.height = height;
    }
}
