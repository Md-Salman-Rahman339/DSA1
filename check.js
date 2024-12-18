function calculateTax(income, expenses) {

    if(income>=0 && expenses>=0){
       const tax=income-expenses;
        return tax*.20;

    }
    else{
        return "Invalid Input"
    }
}

function sendNotification(email) {
    if(!email.includes("@")){
        return "Invalid Email";
    }
    const parts=email.split("@");

    if(parts.length !=2){
        return "Invalid Email";

    }
    const username=parts[0];
    const domain=parts[1];
    return `${username} sent you an email from ${domain}`;
}

function checkDigitsInName(name) {
    if(typeof name!="string" || name.length===0){
        return "Invalid Input";

    }
    for(let i=0;i<=name.length;i++){
        if(!isNaN(name[i])){
            return true;
        }
       
        else{
            return false;

        }
    }
    
}

function calculateFinalScore(obj) {
    if (typeof obj !== 'object' || obj === null ||
        typeof obj.name !== 'string' ||
        typeof obj.testScore !== 'number' || obj.testScore > 50 ||
        typeof obj.schoolGrade !== 'number' || obj.schoolGrade > 30 ||
        typeof obj.isFFamily !== 'boolean') {
        return "Invalid Input";
    }
    let finalScore = obj.testScore + obj.schoolGrade;
    if (obj.isFFamily) {
        finalScore += 20;
    }
    return finalScore >= 80;
}

function waitingTime(waitingTimes, serialNumber) {
    if (!Array.isArray(waitingTimes) || typeof serialNumber !== "number") {
        return "Invalid Input";
    }
    var total = 0;
    for (let i = 0; i < waitingTimes.length; i++) {
        total += waitingTimes[i];
    }
    const average = Math.round(total / waitingTimes.length);
    const remainingPeople = serialNumber - waitingTimes.length - 1;
 
    if (remainingPeople > 0) {
        return remainingPeople * average;
    } else {
        return 0;
    }
}

