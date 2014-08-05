class 'DasLevel' (Level)

function DasLevel:__init()
    Level.__init(self)

    Level.setProperties(self, {
        Name = "Das Level";
    
        StartPosition = Point(1, 2);

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
    
    print (Point.length(Point(1,2), Point(2,3)))
end

--function Level.OnStep(x, y)
--end

--function Level.OnLose()
--end

--function Level.OnWin()
--end

--function Level.OnHit()
--end

