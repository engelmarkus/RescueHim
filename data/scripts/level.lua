class 'DasLevel' (Level)

function DasLevel:__init()
    Level.__init(self)

    Level.setProperties(self, {
        Name = "Das Level";
    
        --StartPosition = Point(1, 2);
	PlayerOne = Player(1, 2);
	
        Size = Size(5, 10);

        Map = {
            1, 1, 1, 1, 1,
            1, 0, 0, 0, 1,
            1, 0, 1, 0, 1,
            1, 0, 0, 0, 1,
            1, 1, 1, 1, 1
        };

        Enemies = {
            Point(3, 2);
            Point(4, 2);
        };
    })
end

function DasLevel:OnStart()
    print "OnStart!"
    print (self.Name)
    
    r1 = Rect(Point(), Size(5, 5))
    r2 = Rect(1, 1, 4, 4)
    
    print("Player position = (" .. self.PlayerOne.position.x .. "; " .. self.PlayerOne.position.y ..")")
    print("Player moves one step left!")
    --Why does that work? it should be seld.PlayerOne.moveTop()!!!
    self.PlayerOne.moveLeft(self.PlayerOne)
    print("Player position = (" .. self.PlayerOne.position.x .. "; " .. self.PlayerOne.position.y ..")")
   
    print (r1:containsRect(r2))
    
    print ("L: " .. r1.Left .. "; T: " .. r1.Top .. "; R: " .. r1.Right .. "; B: " .. r1.Bottom)
    
    r1:offsetBy(Point(1, 2))
    
    print ("L: " .. r1.Left .. "; T: " .. r1.Top .. "; R: " .. r1.Right .. "; B: " .. r1.Bottom)
    
    print (r1:intersectsWith(r2))
    
    r1:offsetBy(Point(4, 3))
    
    print (r1:intersectsWith(r2))
    
    -- sofort terminate, weil in c++11 destruktoren standardmäßig noexcept sind.
    -- => im luabind-code diese destruktoren explizit mit noexcept(false) kennzeichnen.
    --r1.Top = 4
    
    print (r1 == Rect(5, 5, 5, 5))
    
end

--function Level.OnStep(x, y)
--end

--function Level.OnLose()
--end

--function Level.OnWin()
--end

--function Level.OnHit()
--end

