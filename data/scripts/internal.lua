function Level:setProperties(list)
    for k, v in pairs(list) do
        self[k] = v
    end
end