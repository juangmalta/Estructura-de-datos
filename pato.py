import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
password = input("To start the program, enter the password: ")


def q1():
    data = pd.read_excel("databasenintendo.xlsx")
    data.groupby("Platform").get_group("3DS")
    gamename = data3DS["Name"]
    global_sales = data3DS["Global_Sales"]
    mean_descriptor = np.mean(global_sales)
    print("The mean is: ", mean_descriptor)
    middle_element = np.median(global_sales)
    print("The median is: ", middle_element)
    variance = np.var(global_sales)
    print("The variance is: ", variance)
    std = np.std(global_sales)
    print("The standard deviation is: ", std)

    barcolor = ["pink"]
    plt.bar(gamename, global_sales, color=barcolor)
    plt.show()


def q2():

    data = pd.read_excel("databasenintendo.xlsx")

    data = data.groupby("Year_of_Release").get_group("Year 2016")
    game = data07["Name"]
    sales = data07["Global_Sales"]
    mean = np.mean(sales)
    maximum = np.max(sales)
    minimum = np.min(sales)
    variance = np.var(sales)
    print("The average sales, in millions, of 2016 were", mean)
    print("The top game sold, in millions,", maximum)
    print("The worst game sold, in millions,", minimum)
    print("The variance of games in respect to the mean is", variance)

    barcolor = ["purple"]
    plt.barh(game, sales, color=barcolor)
    plt.title("Games sold in 2016")
    plt.xlabel("Sales in millions of dollars")
    plt.ylabel("Nintendo games")
    plt.xticks(rotation=30)
    plt.show()


def q3():
    data = pd.read_excel("databasenintendo.xlsx")
    dataRP = data.groupby("Genre").get_group("RolePlaying")
    gamename = dataRP["Name"]
    NA_Sales = dataRP["NA_Sales"]
    mean_descriptor = np.mean("NA_Sales")
    print("The mean is: ", mean_descriptor)
    middle_element = np.median("NA_Sales")
    print("The median is: ", middle_element)
    variance = np.var("NA_Sales")
    print("The variance is: ", variance)
    std = np.std("NA_Sales")
    print("The standard deviation is: ", std)

    barcolor = ["blue"]
    plt.bar(gamename, NA_Sales, color=barcolor)
    plt.show()


if password == "tacos de canasta":

    while True:

        print("Select an option. A) Top selling game genres. B) Top selling games in 2016. C) Top selling role playing games in North America. D Break")
        option = input("Write the option you desire: ")

        if option == "A":
            q1()

        if option == "B":
            q2()

        if option == "C":
            q3()
