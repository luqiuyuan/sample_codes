vector = [1, 2, 3, 4, 5];
% remove 3
idx = 1;
while idx <= numel(vector)
    if vector(idx) == 3
        vector(idx) = [];
    else
        idx = idx + 1;
    end
end
disp(vector)