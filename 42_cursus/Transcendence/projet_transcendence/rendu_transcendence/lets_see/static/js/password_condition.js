// Récupère l'élément du mot de passe et les icônes de check
const passwordInput = document.getElementById('password');
const confirmPasswordInput = document.getElementById('confirm_password');
const checkLength = document.getElementById('check1');
const checkNumber = document.getElementById('check2');
const checkUppercase = document.getElementById('check3');
const checkSpecial = document.getElementById('check4');

// Fonction pour vérifier les conditions du mot de passe
function checkPassword() {
  const password = passwordInput.value;
  console.log('Mot de passe actuel:', password);  // Affiche le mot de passe actuel pour débogage

  // Vérifie la longueur (min 8 caractères)
  if (password.length >= 8) {
    checkLength.classList.add('checked');
  } else {
    checkLength.classList.remove('checked');
  }

  // Vérifie s'il y a un nombre
  if (/\d/.test(password)) {
    checkNumber.classList.add('checked');
  } else {
    checkNumber.classList.remove('checked');
  }

  // Vérifie s'il y a une majuscule
  if (/[A-Z]/.test(password)) {
    checkUppercase.classList.add('checked');
  } else {
    checkUppercase.classList.remove('checked');
  }

  // Vérifie s'il y a un caractère spécial
  if (/[^A-Za-z0-9]/.test(password)) {
    checkSpecial.classList.add('checked');
  } else {
    checkSpecial.classList.remove('checked');
  }

  // Vérifie si le mot de passe et la confirmation correspondent
  if (password === confirmPasswordInput.value) {
    confirmPasswordInput.setCustomValidity(""); // Réinitialise le message d'erreur
  } else {
    confirmPasswordInput.setCustomValidity("Les mots de passe ne correspondent pas.");
  }

  // Log pour déboguer si le mot de passe et la confirmation correspondent
  console.log('Les mots de passe correspondent ?', password === confirmPasswordInput.value);
}

// Ajoute un événement pour vérifier le mot de passe à chaque saisie
passwordInput.addEventListener('input', checkPassword);
confirmPasswordInput.addEventListener('input', checkPassword);

