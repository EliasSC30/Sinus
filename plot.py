import matplotlib.pyplot as plt

if __name__ == "__main__":
    file = open("pts.txt");
    x = []
    y = []

    i = 0
    for line in file:
        print(line)
        if i % 2 == 0:
            x.append(float(line));
        else:
            y.append(float(line));
        i += 1;

    plt.plot(x,y);
    plt.show()
    #for i in range(len(x)-1):
     #   print(f"x: {x[i]} y:{y[i]}\n");
