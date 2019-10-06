/* Doodle Drawing Library
 *
 * Drawable and Primitive are base classes and have been implemented for you.
 * Do not modify them! 
 *
 * Stubs have been added to indicate where you need to complete the
 * implementation.
 * Please email me if you find any errors!
 */

var loadCount = 0;

/*
 * Root container for all drawable elements.
 */
function Doodle(context) {
    this.context = context;
    this.children = [];
}

Doodle.prototype.draw = function() {
    var that = this;
    // Your draw code here
    if (loadCount != 0) {
        setTimeout(() => {
            that.draw();
        }, 50);
    } else {
        for (var e in this.children) {
            this.children[e].draw(this.context);
        }
    }
};

/* Base class for all drawable objects.
 * Do not modify this class!
 */
function Drawable(attrs) {
    var dflt = {
        left: 0,
        top: 0,
        visible: true,
        theta: 0,
        scale: 1
    };
    attrs = mergeWithDefault(attrs, dflt);
    this.left = attrs.left;
    this.top = attrs.top;
    this.visible = attrs.visible;
    this.theta = attrs.theta * Math.PI / 180;
    this.scale = attrs.scale;
}

/*
 * Summary: returns the calculated width of this object
 */
Drawable.prototype.getWidth = function(context) {
    console.log("ERROR: Calling unimplemented draw method on drawable object.");
    return 0;
}

/*
 * Summary: returns the calculated height of this object
 */
Drawable.prototype.getHeight = function(context) {
    console.log("ERROR: Calling unimplemented draw method on drawable object.");
    return 0;
}

/*
 * Summary: Uses the passed in context object (passed in by a doodle object)
 * to draw itself.
 */
Drawable.prototype.draw = function(context) {
    console.log("ERROR: Calling unimplemented draw method on drawable object.");
};


/* Base class for objects that cannot contain child objects.
 * Do not modify this class!
 */
function Primitive(attrs) {
    var dflt = {
        lineWidth: 1,
        color: "black"
    };
    attrs = mergeWithDefault(attrs, dflt);
    Drawable.call(this, attrs);
    this.lineWidth = attrs.lineWidth;
    this.color = attrs.color;
}
Primitive.inheritsFrom(Drawable);

//Inherits from: Drawable
function Text(attrs) {
    var dflt = {
        content: "",
        fill: "black", //color
        font: "Helvetica", //font family
        size: 12, //Size in pt
        bold: false //bold boolean
    };
    attrs = mergeWithDefault(attrs, dflt);
    Drawable.call(this, attrs);

    //Rest of constructor code here
    this.fill = attrs.fill;
    this.font = attrs.font;
    this.size = attrs.size;
    this.bold = attrs.bold;
    this.content = attrs.content;

    this.measure = MeasureText(this.content, this.bold, this.font, this.size);
}
Text.inheritsFrom(Drawable);

//Text methods here
Text.prototype.getWidth = function(context) {
    return this.measure[0];
}

Text.prototype.getHeight = function(context) {
    return this.measure[1];
}

Text.prototype.draw = function(context) {
    context.save();

    context.font = (this.bold ? "bold " : "") + this.size + "pt " + this.font;
    context.fillStyle = this.fill;
    context.fillText(this.content, this.left, this.top + this.getHeight());

    context.restore();
}

//Inherits from: Drawable
function DoodleImage(attrs) {
    var dflt = {
        width: -1,
        height: -1,
        src: "",
    };
    attrs = mergeWithDefault(attrs, dflt);
    Drawable.call(this, attrs);

    //Rest of constructor code here
    this.width = attrs.width;
    this.height = attrs.height;
    this.src = attrs.src;
    this.img = new Image();
    this.img.src = this.src;

    //实现图片的完全加载
    loadCount++;
    this.imgLoad(this.img);
    this.img.onload = function() {
        console.log("image onload: " + this.src);
    }
}
DoodleImage.inheritsFrom(Drawable);

//DoodleImage methods here
DoodleImage.prototype.getWidth = function(context) {
    var that = this;
    return that.width == -1 ? that.img.naturalWidth : that.width;
}

DoodleImage.prototype.getHeight = function(context) {
    var that = this;
    return that.height == -1 ? that.img.naturalHeight : that.height;
}

DoodleImage.prototype.draw = function(context) {
    context.save();

    console.log("draw image: " + this.img.complete);
    var w = this.getWidth(this.context);
    var h = this.getHeight(this.context);
    context.drawImage(this.img, this.left, this.top, this.getWidth(this.context), this.getHeight(this.context));

    context.restore();
}

//完全加载图片的方法
DoodleImage.prototype.imgLoad = function(img) {
    var timer = setInterval(function() {
        if (img.complete) {
            console.log("image load");
            loadCount--;
            clearInterval(timer);
        }
    }, 50);
}

//Inherits from: Primitive
function Line(attrs) {
    var dflt = {
        startX: 0,
        startY: 0,
        endX: 0,
        endY: 0
    };
    attrs = mergeWithDefault(attrs, dflt);
    Primitive.call(this, attrs);

    //Rest of constructor code here
    this.startX = attrs.startX;
    this.startY = attrs.startY;
    this.endX = attrs.endX;
    this.endY = attrs.endY;
}
Line.inheritsFrom(Primitive);

//Line methods here
Line.prototype.getWidth = function(context) {
    return Math.abs(this.startX - this.endX);
}

Line.prototype.getHeight = function(context) {
    return Math.abs(this.startY - this.endY);
}

Line.prototype.draw = function(context) {
    context.save();

    context.beginPath();
    context.moveTo(this.startX, this.startY);
    context.lineTo(this.endX, this.endY);
    context.lineWidth = this.lineWidth;
    context.strokeStyle = this.color;
    context.stroke();

    context.restore();
}

//Inherits from: Primitive
function Rectangle(attrs) {
    var dflt = {
        x: 0,
        y: 0,
        width: 0,
        height: 0,
    };
    attrs = mergeWithDefault(attrs, dflt);
    Primitive.call(this, attrs);
    //Rest of constructor code here
    this.x = attrs.x;
    this.y = attrs.y;
    this.width = attrs.width;
    this.height = attrs.height;
}
Rectangle.inheritsFrom(Primitive);

//Rectangle Methods here
Rectangle.prototype.getWidth = function(context) {
    return this.width;
}

Rectangle.prototype.getHeight = function(context) {
    return this.height;
}

Rectangle.prototype.draw = function(context) {
    context.save();

    //描边
    context.lineWidth = this.lineWidth;
    context.strokeStyle = this.color;
    context.strokeRect(this.left, this.top, this.width, this.height);

    context.restore();
}

//Inherits from: Drawable
function Container(attrs) {
    var dflt = {
        width: 100,
        height: 100,
        fill: "",
        borderColor: "black",
        borderWidth: 0,
    };
    attrs = mergeWithDefault(attrs, dflt);
    Drawable.call(this, attrs);

    //Rest of constructor code here
    this.children = [];

    this.width = attrs.width;
    this.height = attrs.height;
    this.fill = attrs.fill;
    this.borderColor = attrs.borderColor;
    this.borderWidth = attrs.borderWidth;
}
Container.inheritsFrom(Drawable);

//Rest of container methods here
Container.prototype.getWidth = function(context) {
    return this.width;
}

Container.prototype.getHeight = function(context) {
    return this.height;
};

Container.prototype.draw = function(context) {
    context.save();

    //填充
    if (this.fill != "") {
        context.fillStyle = this.fill;
        context.fillRect(this.left, this.top, this.width, this.height);
    }

    //描边
    if (this.borderWidth > 0) {
        context.strokeStyle = this.borderColor;
        context.borderWidth = this.borderWidth;
        context.strokeRect(this.left, this.top, this.width, this.height);
    }

    //裁剪矩形区域
    context.beginPath();
    context.rect(this.left, this.top, this.width, this.height);
    context.clip();
    context.closePath();

    for (var e in this.children) {
        this.children[e].left += this.left;
        this.children[e].top += this.top;
        this.children[e].draw(context);
    }

    console.log("container drawed");

    context.restore();
};

//Inherits from: Container
function Pile(attrs) {
    Container.call(this, attrs);
    //Rest of constructor code here
}
Pile.inheritsFrom(Container);

//Rest of pile methods here
Pile.prototype.draw = function(context) {
    context.save();

    //填充
    if (this.fill != "") {
        context.fillStyle = this.fill;
        context.fillRect(this.left, this.top, this.width, this.height);
    }

    //描边
    if (this.borderWidth > 0) {
        context.strokeStyle = this.borderColor;
        context.lineWidth = this.borderWidth;
        context.strokeRect(this.left, this.top, this.width, this.height);
    }

    //裁剪矩形区域
    context.rect(this.left, this.top, this.width, this.height);
    context.clip();

    for (var e in children) {
        children[e].left += this.left;
        children[e].top += this.top;
        children[e].draw(context);
    }

    context.restore();
};

//Inherits from: Container
function Row(attrs) {
    Container.call(this, attrs);
    //Rest of constructor code here
}
Row.inheritsFrom(Container);

//Rest of row methods here
Row.prototype.draw = function(context) {
    context.save();

    //填充
    if (this.fill != "") {
        context.fillStyle = this.fill;
        context.fillRect(this.left, this.top, this.width, this.height);
    }

    //描边
    if (this.borderWidth > 0) {
        context.strokeStyle = this.borderColor;
        context.lineWidth = this.borderWidth;
        context.strokeRect(this.left, this.top, this.width, this.height);
    }

    //裁剪矩形区域
    context.rect(this.left, this.top, this.width, this.height);
    context.clip();

    //偏移量
    var offsetLeft = this.left;
    for (var e in this.children) {
        this.children[e].left = offsetLeft;
        this.children[e].top = this.top + (this.getHeight(context) - this.children[e].getHeight(context)) / 2;
        this.children[e].draw(context);

        offsetLeft += this.children[e].getWidth(context);
    }

    context.restore();
};

//Inherits from: Container
function Column(attrs) {
    Container.call(this, attrs);
    //Rest of constructor code here
}
Column.inheritsFrom(Container);

//Rest of row methods here
Column.prototype.draw = function(context) {
    context.save();

    //填充
    if (this.fill != "") {
        context.fillStyle = this.fill;
        context.fillRect(this.left, this.top, this.width, this.height);
    }

    //描边
    if (this.borderWidth > 0) {
        context.strokeStyle = this.borderColor;
        context.lineWidth = this.borderWidth;
        context.strokeRect(this.left, this.top, this.width, this.height);
    }

    //裁剪矩形区域
    context.rect(this.left, this.top, this.width, this.height);
    context.clip();

    //偏移量
    var offsetTop = this.top;
    for (var e in this.children) {
        var w = this.children[e].getWidth(context);
        this.children[e].left = this.left + (this.getWidth(context) - this.children[e].getWidth(context)) / 2;
        this.children[e].top = offsetTop;
        this.children[e].draw(context);

        offsetTop += this.children[e].getHeight(context);
    }

    context.restore();
};

//Inherits from: Container
function Circle(attrs) {
    Container.call(this, attrs);
    var dflt = {
        layoutCenterX: this.width / 2,
        layoutCenterY: this.height / 2,
        layoutRadius: Math.min(this.width, this.height) / 2 - 30
    };
    attrs = mergeWithDefault(attrs, dflt);

    //Rest of constructor code here
    this.layoutCenterX = attrs.layoutCenterX;
    this.layoutCenterY = attrs.layoutCenterY;
    this.layoutRadius = attrs.layoutRadius;
}
Circle.inheritsFrom(Container);

//Rest of circle methods here
Circle.prototype.getWidth = function(context) {
    return Math.min(this.width, this.height);
};

Circle.prototype.getHeight = function(context) {
    return Math.min(this.width, this.height);
};

Circle.prototype.draw = function(context) {
    context.save();

    context.beginPath();
    context.arc(this.layoutCenterX, this.layoutCenterY, Math.min(this.width, this.height), 0, 2 * Math.PI);
    //填充
    if (this.fill != "") {
        context.fillStyle = this.fill;
        context.fill();
    }

    //描边
    if (this.borderWidth > 0) {
        context.strokeStyle = this.borderColor;
        context.lineWidth = this.borderWidth;
        context.stroke();
    }

    //裁剪圆形区域
    context.clip();

    //偏移量
    var interval = 360.0 / this.children.length;
    var degree = 0,
        offsetLeft = this.left + this.layoutRadius,
        offsetTop = this.top;
    for (var e in this.children) {
        this.children[e].left += offsetLeft + this.layoutRadius - Math.sin((90 - degree) / 180.0 * Math.PI) * this.layoutRadius;
        this.children[e].top += offsetTop + Math.cos((90 - degree) / 180.0 * Math.PI) * this.layoutRadius;
        this.children[e].draw(context);

        degree += interval;
    }

    context.restore();
}

//Inherits from: Container
function OvalClip(attrs) {
    Container.call(this, attrs);
    //Rest of constructor code here
}
OvalClip.inheritsFrom(Container);

//Rest of ovalClip methods here
OvalClip.prototype.draw = function(context) {
    context.save();
    //x,y为椭圆中心；a,b分别为椭圆横半轴、
    var a = this.getWidth(context) / 2,
        b = this.getHeight(context) / 2;
    var x = this.left + a,
        y = this.top + b;
    //选择a、b中的较大者作为arc方法的半径参数
    var r = (a > b) ? a : b;
    var ratioX = a / r; //横轴缩放比率
    var ratioY = b / r; //纵轴缩放比率
    context.scale(ratioX, ratioY); //进行缩放（均匀压缩）
    context.beginPath();
    //从椭圆的左端点开始逆时针绘制
    context.moveTo((x + a) / ratioX, y / ratioY);
    context.arc(x / ratioX, y / ratioY, r, 0, 2 * Math.PI);
    context.closePath();

    //填充
    if (this.fill != "") {
        context.fillStyle = this.fill;
        context.fill();
    }

    //描边
    if (this.borderWidth > 0) {
        context.strokeStyle = this.borderColor;
        context.lineWidth = this.borderWidth;
        context.stroke();
    }

    //裁剪椭圆形区域
    context.clip();

    for (var e in this.children) {
        this.children[e].left += this.left;
        this.children[e].top += this.top;
        this.children[e].draw(context);
    }

    context.restore();
};

/**
 * Measurement function to measure canvas fonts
 *
 * @return: Array with two values: the first [0] is the width and the seconds [1] is the height 
 *          of the font to be measured. 
 **/
function MeasureText(text, bold, font, size) {
    // This global variable is used to cache repeated calls with the same arguments
    var str = text + ':' + bold + ':' + font + ':' + size;
    if (typeof(__measuretext_cache__) == 'object' && __measuretext_cache__[str]) {
        return __measuretext_cache__[str];
    }

    var div = document.createElement('DIV');
    div.innerHTML = text;
    div.style.position = 'absolute';
    div.style.top = '-100px';
    div.style.left = '-100px';
    div.style.fontFamily = font;
    div.style.fontWeight = bold ? 'bold' : 'normal';
    div.style.fontSize = size + 'pt';
    document.body.appendChild(div);

    var size = [div.offsetWidth, div.offsetHeight];

    document.body.removeChild(div);

    // Add the sizes to the cache as adding DOM elements is costly and can cause slow downs
    if (typeof(__measuretext_cache__) != 'object') {
        __measuretext_cache__ = [];
    }
    __measuretext_cache__[str] = size;

    return size;
}