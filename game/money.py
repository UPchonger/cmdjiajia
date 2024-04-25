import random  
import time  
  
print("欢迎来到du狗游戏，在这里，赢：拿钱，输：④")  
  
time.sleep(1)  
  
name = input("请签生④状（你的名字）：")  
  
zd = random.randint(4, 10)  # 总子弹数  
zdsk = [0] * zd  # 子弹状态列表，0代表空弹，1代表实弹  
  
# 实弹数量
shi = random.randint(0, zd)  
xue = random.randint(2, 6)  # 初始生命值  
ju = 0  # 当前开枪位置  
mema = True  # 玩家开枪  
em = xue  # 恶魔生命值  
me = xue  # 玩家生命值  
gameopen = True  # 游戏运行或退出bool
sjzdma = False
  
def sjzd():  
    global shi, zd, zdsk, mema, shi
    if sjzdma:
        zd = random.randint(4, 10)  # 总子弹数  
        zdsk = [0] * zd  # 子弹状态列表，0代表空弹，1代表实弹  

        # 实弹数量
        shi = random.randint(0, zd)  
        mema = True
    for _ in range(zd - shi):  # 填充空弹  
        while True:  
            position = random.randint(0, zd - 1)  
            if zdsk[position] == 0:  
                zdsk[position] = 0  
                break  
    for _ in range(shi):  # 填充实弹  
        while True:  
            position = random.randint(0, zd - 1)  
            if zdsk[position] == 0:  
                zdsk[position] = 1  
                break  
    print(f"当前子弹总数：{zd}，其中实弹数量：{shi}")  
    time.sleep(1)  
  
def heart():  
    print("恶魔", end=" ")  
    for i in range(em):  
        print("♥", end="")  
    print("|", end="")  
    print(name, end=" ")  
    for i in range(me):  
        print("♥", end="")  
    print()  
  
def kq():  
    global mema, me, ju, em, shi, gameopen, sjzdma
    if mema and me > 0:  # 玩家开枪且玩家生命值大于0  
        kqq = input("打自己还是打恶魔？(a或b)：")  
        if kqq == "a":  
            if zdsk[ju] == 1:  
                me -= 1  
                print(f"你击中了自己，剩余生命值：{me}") 
                time.sleep(1) 
                zdsk[ju] = 0  # 子弹打完后变为空弹  
                shi -= 1  # 实弹数量减一  
                if me <= 0:  # 玩家生命值耗尽，游戏结束  
                    print("游戏结束，你输了！")  
                    gameopen = False
            else:  
                print("没有击中！")  
                time.sleep(1)
        elif kqq == "b":  
            if zdsk[ju] == 1:  
                em -= 1  
                print(f"你击中了恶魔，恶魔剩余生命值：{em}")  
                time.sleep(1)
                zdsk[ju] = 0  # 子弹打完后变为空弹  
                shi -= 1  # 实弹数量减一  
                mema = False  # 接下来恶魔开枪  
            else:  
                print("没有击中！")  
                mema = False
                time.sleep(1)
        else:  
            print("请输入a或b!")  
            ju -= 1
    elif not mema and em > 0:  # 恶魔开枪且恶魔生命值大于0  
        if zdsk[ju] == 1:
            me -= 1  
            print(f"恶魔击中了你，你剩余生命值：{me}")  
            time.sleep(1)
            if me <= 0:  # 玩家生命值耗尽，游戏结束  
                print("游戏结束，你输了！")  
                gameopen = False
        else:  
            print("恶魔没有击中你！") 
            time.sleep(1) 
        mema = True  # 恶魔射击后，玩家再次获得射击机会  
    elif em <= 0:  # 恶魔生命值耗尽，玩家胜利  
        print("游戏结束，你赢了！你赚到了114514USD!(bushi)")  
        gameopen = False
    ju += 1  # 无论是否击中，都移动到下一个位置  
    if ju == zd:  # 如果到达最后一个位置，重新布置子弹  
        ju = 0  
        sjzdma = True
        sjzd()  # 重新布置子弹并输出子弹状态  
  
# 初始布置子弹  
sjzd()  
  
while gameopen:  
    heart()  
    time.sleep(1)  
    kq()  
