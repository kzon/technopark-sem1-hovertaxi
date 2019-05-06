#!groovy

node {

  properties([[
      $class: 'BuildDiscarderProperty',
      strategy: [
        $class: 'LogRotator',
        artifactDaysToKeepStr: '',
        artifactNumToKeepStr: '',
        daysToKeepStr: '',
        numToKeepStr: '5'
      ]
  ]]);

  runCheckoutStage()
  try {
    runTestStage()
    currentBuild.result = 'SUCCESS'
  } catch(err) {
    currentBuild.result = 'FAILED'
  }
}

def runCheckoutStage() {
  stage 'Checkout'
  checkout scm
}

def runTestStage(){
    stage 'Tests'
    sh 'sh docker/bin/tests.sh'
}