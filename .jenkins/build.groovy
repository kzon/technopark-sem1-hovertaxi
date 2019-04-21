#!groovy

node {

    try{
        runTestsStage()
        currentBuild.result = 'SUCCESS'
    } catch(err){
        currentBuild.result = 'FAILED'
    }
}

def runTestsStage(){
    stage 'Tests'
    sh 'sh docker/bin/tests.sh'
}