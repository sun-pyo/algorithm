def get_grade(avg_score):
    if avg_score >= 90:
        return 'A'
    elif avg_score >= 80:
        return 'B'
    elif avg_score >= 70:
        return 'C'
    elif avg_score >= 50:
        return 'D'
    else:
        return 'F'

def solution(scores):
    answer = ''
    num = len(scores)
    for i in range(num):
        sum = 0
        max_num = 0
        max_count = 0 
        min_num = 100
        min_count = 0
        for j in range(num):
            sum += scores[j][i]
            if scores[j][i] > max_num:
                max_num = scores[j][i]
                max_count = 1
            elif scores[j][i] == max_num:
                max_count+=1
                
            if scores[j][i] < min_num:
                min_num = scores[j][i]
                min_count = 1
            elif scores[j][i] == min_num:
                min_count+=1
        count = len(scores[i])
        if (max_num == scores[i][i] and max_count == 1) or (min_num == scores[i][i] and min_count == 1):
            count-=1
            sum -= scores[i][i]
        grade = get_grade(sum/count)
        answer += grade
    return answer