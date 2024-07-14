from PIL import Image, ImageDraw
from mandelbrot import mandelbrot, MAX_ITER
from math import log

# Image size (pixels)
WIDTH = 2000
HEIGHT = 1300

# Plot window
RE_START = -2.5
RE_END = 1.5
IM_START = -1.5
IM_END = 1.5

im = Image.new('HSV', (WIDTH, HEIGHT), (0, 0, 0))
draw = ImageDraw.Draw(im)

for x in range(0, WIDTH):
    for y in range(0, HEIGHT):
        # Convert pixel coordinate to complex number
        c = complex(RE_START + (x / WIDTH) * (RE_END - RE_START),
                    IM_START + (y / HEIGHT) * (IM_END - IM_START))
        # Compute the number of iterations
        m = mandelbrot(c)
        # The color depends on the number of iterations
        if 1<m<=10:
            hue = int(600 * m / MAX_ITER)+m
            saturation = 600
        elif 10<m<=20:
            hue = int(600 * m / MAX_ITER)+2*m
            saturation = 600
        elif 30<m<=40:
            hue = int(600 * m / MAX_ITER)+3*m
            saturation = 600
        elif 40<m<=50:
            hue = int(600 * m / MAX_ITER)+4*m
            saturation = 600
        elif 60<m<=70:
            hue = int(600 * m / MAX_ITER)+5*m
            saturation = 600
        elif 80<m<=90:
            hue = int(600 * m / MAX_ITER)+6*m
            saturation = 25
        elif 90<m<=100:
            hue = int(600 * m / MAX_ITER)+7*m
            saturation = 600
        elif 100<m<=110:
            hue = int(600 * m / MAX_ITER)+8*m
            saturation = 600
        elif 110<m<=120:
            hue = int(600 * m / MAX_ITER)+9*m
            saturation = 600
        elif 120<m<=130:
            hue = int(600 * m / MAX_ITER)+11*m
            saturation = 600
        elif 130<m<=140:
            hue = int(600 * m / MAX_ITER)+12*m
            saturation = 600
        elif 140<m<=150:
            hue = int(600 * m / MAX_ITER)+13*m
            saturation = 600
        elif 160<m<=170:
            hue = int(600 * m / MAX_ITER)+14*m
            saturation = 600
        elif 180<m<=190:
            hue = int(600 * m / MAX_ITER)+15*m
            saturation = 600
        elif 190<m<=200:
            hue = int(600 * m / MAX_ITER)+16*m
            saturation = 25
        elif 200<m<=210:
            hue = int(600 * m / MAX_ITER)+17*m
            saturation = 600
        elif 210<m<=220:
            hue = int(600 * m / MAX_ITER)+18*m
            saturation = 600
        elif 220<m<=230:
            hue = int(600 * m / MAX_ITER)+19*m
            saturation = 600
        elif 230<m<=240:
            hue = int(600 * m / MAX_ITER)+20*m
            saturation = 600
        elif 240<m<=250:
            hue = int(600 * m / MAX_ITER)+21*m
            saturation = 600
        elif 250<m<=260:
            hue = int(600 * m / MAX_ITER)+22*m
            saturation = 600
        elif 270<m<=280:
            hue = int(600 * m / MAX_ITER)+23*m
            saturation = 600
        elif 280<m<=290:
            hue = int(600 * m / MAX_ITER)+24*m
            saturation = 600
        elif 300<m<=310:
            hue = int(600 * m / MAX_ITER)+25*m
            saturation = 25
        elif 310<m<=320:
            hue = int(600 * m / MAX_ITER)+27*m
            saturation = 600
        elif 320<m<=330:
            hue = int(600 * m / MAX_ITER)+28*m
            saturation = 600
        elif 330<m<=340:
            hue = int(600 * m / MAX_ITER)+29*m
            saturation = 600
        else:
            hue= int(600 * m / MAX_ITER)
            saturation = 600
        value = 600 if m < MAX_ITER else 0
        # Plot the point
        draw.point([x, y], (hue, saturation, value))

im.convert('RGB').save('output20.png', 'PNG')


