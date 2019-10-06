package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.provider.ContactsContract;

public class OvalClip extends BaseVisualElement {
    public OvalClip(float xLoc, float yLoc, float width, float height) {
        super(xLoc, yLoc, width, height);
    }
    @Override
    public void draw(Canvas onCanvas) {//剪切出椭圆的图案
        Path path = new Path();
        path.addOval(new RectF(0, 0, getW(), getH()), Path.Direction.CCW);
        onCanvas.clipPath(path);
        super.draw(onCanvas);
    }
}
